; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_14 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x334546 (bvmul arg0_6 arg1_14)))
(let ((?x347126 (bvmul (_ bv4294967295 32) ?x334546)))
(let ((?x492026 (bvmul arg0_6 arg1_11)))
(let ((?x108790 (bvadd ?x492026 ?x347126)))
(and (distinct ?x108790 (_ bv0 32)) true))))))
(check-sat)
