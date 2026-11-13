; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_35 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg1_28 () (_ BitVec 32))
(assert
 (let ((?x63856 (bvmul arg0_11 arg1_35)))
(let ((?x64541 (bvmul (_ bv4294967295 32) ?x63856)))
(let ((?x63664 (bvmul arg0_11 arg1_28)))
(let ((?x60575 (bvadd ?x63664 ?x64541)))
(and (distinct ?x60575 (_ bv0 32)) true))))))
(check-sat)
