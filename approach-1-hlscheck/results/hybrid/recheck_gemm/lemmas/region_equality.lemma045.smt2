; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_11 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg1_14 () (_ BitVec 32))
(assert
 (let ((?x194 (bvmul arg0_15 arg1_11)))
(let ((?x9169 (bvmul (_ bv4294967295 32) ?x194)))
(let ((?x125 (bvmul arg0_15 arg1_14)))
(let ((?x10546 (bvadd ?x125 ?x9169)))
(and (distinct ?x10546 (_ bv0 32)) true))))))
(check-sat)
