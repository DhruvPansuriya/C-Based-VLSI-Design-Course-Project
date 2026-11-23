; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg1_9 () (_ BitVec 32))
(assert
 (let ((?x155 (bvmul arg0_10 arg1_6)))
(let ((?x21575 (bvmul (_ bv4294967295 32) ?x155)))
(let ((?x214 (bvmul arg0_10 arg1_9)))
(let ((?x5753 (bvadd ?x214 ?x21575)))
(and (distinct ?x5753 (_ bv0 32)) true))))))
(check-sat)
