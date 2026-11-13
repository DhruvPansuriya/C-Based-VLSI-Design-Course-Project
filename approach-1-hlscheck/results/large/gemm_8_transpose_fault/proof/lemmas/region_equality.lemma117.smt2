; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_5 () (_ BitVec 32))
(declare-fun arg0_21 () (_ BitVec 32))
(declare-fun arg1_40 () (_ BitVec 32))
(assert
 (let ((?x75206 (bvmul arg0_21 arg1_5)))
(let ((?x13068 (bvmul (_ bv4294967295 32) ?x75206)))
(let ((?x45169 (bvmul arg0_21 arg1_40)))
(let ((?x74878 (bvadd ?x45169 ?x13068)))
(and (distinct ?x74878 (_ bv0 32)) true))))))
(check-sat)
